**`Lab1/Task1-1/report.md`（完整示範報告）**

```markdown
# 課題報告：Task 1-1 Using the Variable Resistor to Adjust LED Lightness

- **學生姓名**：[林語柔]
- **學生學號**：[113511088]
- **完成日期**：2026-09-13

---

### 1. 實驗目標(可參考課程投影片寫法)
- 使用 Arduino Uno 的 `analogRead()` 讀取可變電阻（Variable Resistor / Potentiometer）的類比輸入值。
- 將可變電阻讀取到的數值轉換成 LED 的 PWM 輸出值。
- 使用 `analogWrite()` 控制 LED 亮度，使可變電阻數值越大時 LED 越亮。
- 使用 `Serial.println()` 每秒在 Serial Monitor 顯示一次可變電阻的類比輸入值。
- 理解 Arduino Uno 的 ADC（Analog-to-Digital Converter）以及 `analogRead()` 的數值範圍。

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- 麵包板 x 1
- 可變電阻（Potentiometer）x 1
- LED x 1
- Jumper Wires x 5

### 3. 操作說明與成果
1. **燒錄程式**：使用 USB 線連接 Arduino Uno 至電腦，開啟 `Task1-1.ino` 並點擊「上傳」。
2. **開啟監控器**：開啟 Arduino IDE 的 Serial Monitor，將鮑率（Baud rate）設為 **9600 baud**。
3. **實驗成果**：旋轉可變電阻時，Serial Monitor 會顯示目前的類比輸入值，LED 亮度也會隨數值大小改變。
4. **操作影片**：請參閱同目錄下 `video/Task1-1.mp4` 之實際操作畫面。
