需要讨论的方案?
================

***

单片机选择
---------

+ Arduino Uno

+ STM32f103c8t6

***

STM32配置
------------
+ 时钟


携带模块
------------

+ (micro)SD卡读取
  - 5V, GND
  - SPI
  - CS 连个GPIO

+ 空气质量传感器 MQ135
  - 模拟输出: 
  - TTL输出
  - GND + 5V

+ 加速度传感器 GY-521 MPU6050
  - I2C
    - (43) PB7: SDA
    - (42) PB6: SCL
  - GND (47) VSS 
  - VCC (48) 3~5V

+ 数传 E32-433T20S
  - GND + 3.3~5V
  - 两个TTL作I/O

+ 电源(STM32)
  

  
