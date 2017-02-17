#include <iostream>
#include <thread>
#include <memory>
#include <atomic>

std::atomic<bool> gSyncUsersThreadRun;

void push(std::function<void()> callback)
{
	callback();
}

void sync(std::function<void()> callback)
{
	callback();
}

std::unique_ptr<std::thread> get_thread()
{
    return std::unique_ptr<std::thread>(new std::thread([]()
    {
        while (gSyncUsersThreadRun.load())
        {
            std::this_thread::sleep_for(std::chrono::seconds(1);

            try
            {
                std::cout << "Try update sync user in background mode" << std::endl;

                if (false)
                {
                    int i = 10;

                    sync([]()
                    {
                        push([]()
                        {
                            int j = 10;
                        });
                    });
                }

                std::cout << "Sync user finished" << std::endl;
            }
            catch (const char * e)
            {
                std::cout << "Sync user finished" << std::endl;
            }
            catch (const std::exception& ex)
            {
            	std::cout << "Exception: " << ex.what() << "Sync with auth server was failed" << std::endl;
            }
            catch (...)
            {
            	std::cout << "Got exception while processing request. Sync with auth server was failed" << std::endl;
            }
        }
    }));
}

int main()
{
	gSyncUsersThreadRun.store(true);
	auto thread = get_thread();

	std::this_thread::sleep_for(std::chrono::seconds(5));

	gSyncUsersThreadRun.store(false);
	thread->join();

	return 0;
}