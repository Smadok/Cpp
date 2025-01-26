#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

class Pool {
private:
    double water_level;  
    const double max_capacity = 2000.0; 
    const double min_level = 800.0;  
    std::mutex mtx;  

public:
    Pool() : water_level(0.0) {}

    void drain_10() {
        
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::lock_guard<std::mutex> lock(mtx);
            if (water_level <= 0) break;  
            water_level -= 10;
            std::cout << "Drained 10 m³, current level: " << water_level << " m³" << std::endl;
        }
    }

    void drain_5() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::lock_guard<std::mutex> lock(mtx);
            if (water_level <= 0) break;
            water_level -= 5;
            std::cout << "Drained 5 m³, current level: " << water_level << " m³" << std::endl;
        }
    }

    void fill_20() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::lock_guard<std::mutex> lock(mtx);
            if (water_level >= max_capacity) break; 
            water_level += 20;
            std::cout << "Filled 20 m³, current level: " << water_level << " m³" << std::endl;
        }
    }

    void start_filling() {
        std::thread t1(&Pool::drain_10, this);
        std::thread t2(&Pool::drain_5, this);

        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::lock_guard<std::mutex> lock(mtx);
            if (water_level >= min_level) {
                std::cout << "Water level reached 800 m³, starting fill pipe." << std::endl;
                std::thread fill_thread(&Pool::fill_20, this);
                fill_thread.join();
                break;
            }
        }

        t1.join();  
        t2.join();  

        std::cout << "Cycle complete! Current water level: " << water_level << " m³" << std::endl;
    }
};

int main() {
    Pool pool;
    pool.start_filling();
    return 0;
}
