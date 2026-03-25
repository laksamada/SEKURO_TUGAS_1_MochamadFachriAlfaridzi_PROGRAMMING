#pragma once

#include "mcu.hpp"

class mcu_walker:public MCU{
private:
    int motor_speed;
    int rotation;
public:
    mcu_walker(float cpu_speed,int memory,std::string os,std::string nama,int volt,int motor_speed,int rotation);
    void rotate(int rotation);
    void increase_speed(int speed);
    void showSpek() override;
    void nambah_volt(int penambahan_voltase) override;
    void ganti_os(std::string new_os) override;
    ~mcu_walker() override;
};
