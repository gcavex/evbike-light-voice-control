#include "led_control.h"

static int brightness = 0;
static int direction = 1;

// 当前“呼吸速度”，数值越大，变化越快
static int breath_speed = 1;

void led_init(void)
{
    // 预留硬件初始化
}

void led_purple_breathing(void)
{
    // 在中间亮度时加快变化（模拟肌肉发力）
    if (brightness > 50 && brightness < 200)
    {
        breath_speed = 3;
    }
    else
    {
        breath_speed = 1;
    }

    // 根据方向改变亮度
    brightness += direction * breath_speed;

    // 亮度上限
    if (brightness >= 255)
    {
        brightness = 255;
        direction = -1;   // 开始“呼气”
    }
    // 亮度下限
    else if (brightness <= 0)
    {
        brightness = 0;
        direction = 1;    // 开始“吸气”
    }
}

