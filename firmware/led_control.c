#include "led_control.h"

// 呼吸灯亮度变量（0 ~ 255）
static int brightness = 0;

// 亮度变化方向：1 表示变亮，-1 表示变暗
static int direction = 1;

void led_init(void)
{
    // 这里将来放：GPIO / PWM 初始化
    // 现在先留空，确保结构正确
}

void led_purple_breathing(void)
{
    // 改变亮度
    brightness += direction;

    // 到达最亮或最暗时，反转方向
    if (brightness >= 255)
    {
        brightness = 255;
        direction = -1;
    }
    else if (brightness <= 0)
    {
        brightness = 0;
        direction = 1;
    }

    // 这里将来会把 brightness
    // 映射到 RGB 的紫色通道
    // 现在先当“逻辑正确”
}

