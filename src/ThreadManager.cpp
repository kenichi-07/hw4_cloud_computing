#include "ThreadManager.h"

ThreadManager::ThreadManager() {
}

ThreadManager::~ThreadManager() {
    joinAll(); // Ensure all threads are joined on destruction
}

void ThreadManager::executeTasks(int num_threads, std::function<void()> task) {
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(task);
    }
    joinAll(); // Wait for all threads to complete before exiting the function
}

void ThreadManager::joinAll() {
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    threads.clear(); // Clear the thread list after joining
}
