#include "ThreadEngine.h"



thread_pool::thread_pool(const int threads) : shutdown_(false) 
{

	for (int i = 0; i < threads; ++i)
		threads_.emplace_back(std::bind(&thread_pool::threadEntry, this, i));
}

thread_pool::~thread_pool()
{
	
	{

		std::unique_lock <std::mutex> l(lock_);
		shutdown_ = true;

	}

	condVar_.notify_all();

	for (auto& thread : threads_)
		thread.join();

	threads_.clear();
	stopped_ = true;
	std::cout << "**************Please Wait******************" << std::endl;

}

void thread_pool::execute(std::function<void()> func)
{
    std::unique_lock <std::mutex> l(lock_);
    jobs_.emplace(std::move(func));
    condVar_.notify_one();
}

void thread_pool::threadEntry(int i)
{
	std::function <void(void)> job;

	while (true)
	{
		{
			std::unique_lock <std::mutex> l(lock_);

			while (!shutdown_ && jobs_.empty())
				condVar_.wait(l);
			if (jobs_.empty())
			{
				
				return;
			}
			
			job = std::move(jobs_.front());
			jobs_.pop();
		}

		job();
	}

}