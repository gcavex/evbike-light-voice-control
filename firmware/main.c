#include <Arduino.h>      // Arduino基础库（让ESP32能用setup/loop）
#include <FastLED.h>      // 控制灯带的库（核心）

// ================== 基本配置 ==================

#define LED_PIN 2         // 数据线接的引脚（你接的是GPIO2）
#define NUM_LEDS 10       // 灯的数量（先写10，避免供电不够）
#define BRIGHTNESS 100    // 亮度（范围0~255，先别太亮）

CRGB leds[NUM_LEDS];      // 定义一个“灯数组”，每个灯都有RGB颜色

// ================== 初始化（只执行一次） ==================
void setup() {

  // 告诉FastLED：灯带类型、引脚、颜色顺序
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  // 设置整体亮度（不会改变颜色比例，只是整体变亮/暗）
  FastLED.setBrightness(BRIGHTNESS);
}

// ================== 主循环（一直重复执行） ==================
void loop() {

  // ---------- 第一段：慢慢变亮 ----------
  for (int b = 0; b < 255; b++) {   // b从0增加到255（亮度逐渐增加）

    for (int i = 0; i < NUM_LEDS; i++) {  // 遍历每一颗灯

      // 设置颜色（紫色）
      // 红色 = b/2（少一点）
      // 蓝色 = b（多一点）
      // 绿色 = 0
      leds[i] = CRGB(b/2, 0, b);

    }

    FastLED.show();   // 把颜色“发送”到灯带（必须有这句）

    delay(10);        // 延时10毫秒（控制变化速度）
  }

  // ---------- 第二段：慢慢变暗 ----------
  for (int b = 255; b > 0; b--) {  // b从255减少到0（亮度降低）

    for (int i = 0; i < NUM_LEDS; i++) {  // 再次遍历每一颗灯

      leds[i] = CRGB(b/2, 0, b);   // 颜色逻辑和上面一样

    }

    FastLED.show();   // 更新灯带

    delay(10);        // 控制速度
  }
}
