#include "StandardHeaderIncludes.hpp"

namespace Utils
{
    class Timer
    {
        private:
            std::chrono::duration<int64_t, std::nano> duration;
            std::chrono::time_point<std::chrono::high_resolution_clock> prev, curr, temp;
            int64_t timeElapsed = -1;

            void updateTimeElapsed()
            {
                duration = curr - prev;
                timeElapsed = duration.count();
                return ;
            }
            
        public:
            Timer()
            {
                return ;
            }

            void addTimePoint()
            {
                temp = std::chrono::high_resolution_clock::now();
                prev = curr;
                curr = temp;
                return ;
            }

            int64_t getTimeElapsed()
            {
                updateTimeElapsed();
                return timeElapsed;
            }
    };
}