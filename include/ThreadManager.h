#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <thread>
#include <vector>
#include <functional>

class ThreadManager {
public:
    ThreadManager();
    ~ThreadManager();

    // Disable copy and move semantics
    ThreadManager(const ThreadManager&) = delete;
    ThreadManager& operator=(const ThreadManager&) = delete;
    ThreadManager(ThreadManager&&) = delete;
    ThreadManager& operator=(ThreadManager&&) = delete;

    // Executes a task across multiple threads
    void executeTasks(int num_threads, std::function<void()> task);

private:
    std::vector<std::thread> threads;

    // Helper to join all threads
    void joinAll();
};

#endif // THREADMANAGER_H
