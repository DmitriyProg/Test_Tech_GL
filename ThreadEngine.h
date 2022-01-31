#pragma once
#include "stdafx.h"

class thread_pool
{
public:

	explicit thread_pool(int threads);
	thread_pool();
	~thread_pool();

    void execute(std::function <void(void)> func);
     
protected:

    void threadEntry(int i);
    std::mutex lock_;
    std::condition_variable condVar_;
    bool shutdown_ = false;
    std::queue <std::function <void(void)>> jobs_;
    std::vector <std::thread> threads_;
    
    bool stopped_ = false;
};