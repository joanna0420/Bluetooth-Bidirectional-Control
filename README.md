# Bluetooth-Bidirectional-Control

```markdown
# 課題報告：Task 4-1 Bluetooth-Bidirectional-Control

- **學生姓名**：[林玉惠] [林語柔]
- **學生學號**：[113511209] [113511088]
- **完成日期**：2026-10-01

---

### 1. 實驗目標(可參考課程投影片寫法)
1. 雙向藍牙無線通訊：利用兩組 HC-05 藍牙模組分別設定為 Master 與 Slave，建立配對連線並實作雙向即時資料傳輸協定。   
2. 硬體感測與驅動控制：實現 A 端按 Button 遠端控制 B 端 LED 的亮暗。 實現 B 端可變電阻透過類比訊號讀取與對應數值傳輸，即時調控 A 端直流馬達的轉速。   
3. GitHub 團隊協作開發：練習 Git 工作流程，包含建立Repository、管理檔案目錄架構、角色分配（Project Manager 與 Collaborator）。 實作 Feature Branch 管理、Commit ，以及使用 GitHub Pull Request 與 Code Review 完成專案合併。

### 2. 設備與元件

Student A (Master):
- Arduino Uno x 1
- HC-05 藍牙模組 x 1
- 按鈕 x 1
- 直流馬達 與 驅動電路
- 麵包板與杜邦線 x N

Student B (Slave):
- Arduino Uno x 1
- HC-05 藍牙模組 x 1
- 可變電阻 x 1
- LED 與 限流電阻 x 1
- 麵包板與杜邦線 x N


### 3. 操作說明與成果
1. 協作架構與 Git 分工流程Repository 架構：

Bluetooth-Bidirectional-Control/
├── README.md               # 雙方共同維護與任務說明
├── Master_Node/
│   └── Master_Node.ino     # Student A 開發與維護
└── Slave_Node/
    └── Slave_Node.ino      # Student B 開發與維護

2. 工作流程：   
- Student A (Project Manager)：建立公開 Repo 並初始化目錄結構，
    邀請 Student B 為 Collaborator；各自建立專屬分支進行開發，
    最後負責審核 PR 並合併至 main 分支。   
- Student B (Collaborator)：Clone 儲存庫後建立 feature/
    slave-firmware 分支，於 Slave_Node/ 目錄編寫程式碼並 Push 發送 Pull Request。

3. 節點操作說明與邏輯
Master 端 (Student A)：   
- 連線與角色：HC-05 進入 AT 模式設定為 ROLE=1 (Master)，主動連線
  至 Slave 的藍牙 MAC 位址。
- 操作：按下或釋放按鈕時，透過序列埠傳送控制字元給 Slave。持續監聽
  來自 Slave 的馬達轉速數值（0~255），透過 analogWrite() 輸出對應的 PWM 訊號以驅動直流馬達轉速，並同步印出於序列埠監控視窗。   

Slave 端 (Student B)：   
- 連線與角色：HC-05 設定為 ROLE=0 (Slave)，等待 Master 自動連線。   
- 操作與程式實作：LED 控制：即時讀取序列埠接收到的指令，當收到
  '1' 時點亮 LED，收到 '0' 時熄滅 LED。   
- 可變電阻轉速傳送：以 50ms 為週期透過 analogRead(A0) 讀取
  01023 之類比電壓值，經 map() 轉換為 0255 的 PWM 數值。當數值變化大於門檻值（防止雜訊抖動）時，透過藍牙發送單一位元組給 Master。   
4. 成果展示功能驗證：
- 按鈕遠端開關燈：按下 Student A 的按鈕時，Student B 麵包板上的
  藍色 LED 瞬間點亮；放開按鈕時 LED 即刻熄滅，反應延遲極低。   
- 控制馬達速度：旋轉 Student B 的可變電阻時，Student A 側的直流
  馬達轉速隨之增減；由 Serial Monitor 可見接收到的 Motor Speed 數值由 0 至 255 連續變化，達成即時的雙向無線控制。 
