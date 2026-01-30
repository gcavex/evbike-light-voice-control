#include "led_control.h"

int main(void)
{
    // 初始化灯光系统
    led_init();

    // 主循环
    while (1)
    {
        // 执行紫色呼吸灯效果
        led_purple_breathing();

        // 这里将来会加延时函数
        // 用来控制呼吸速度
    }

    return 0;
}

