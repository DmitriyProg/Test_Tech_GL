#pragma once
#include "stdafx.h"
#define COOUNTER = 0;
#define MAX_THREAD 8
#define  ROOT = "C:\\";

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

class finder_engine
{
public:

	std::atomic<bool> exit_thread_flag{ false };
	finder_engine();
	std::vector<std::string>
	getListSubDir(std::string const& dir, std::string const& app_name);
	inline std::vector<std::string> getListOfDrives();
	int get_num_thread();

	std::string get_path_by_name(std::string const& app_name);

  void Finder(std::string const& dir, std::string const& name, std::string& result);

};
