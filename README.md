# AstroBot

AstroBot is a Discord bot built using **C++** and the **D++ (DPP) library**.

## **Setup Instructions**

### **1. Install Dependencies**
Ensure you have **vcpkg** installed and properly set up. Then, install **DPP**:

```sh
vcpkg install dpp:x64-windows
```

or if you prefer a static library:

```sh
vcpkg install dpp:x64-windows-static
```

### **2. Securely Storing the Bot Token**
For security reasons, **DO NOT** hardcode the bot token in your source code. Instead, store it as an **environment variable**.

#### **On Windows (PowerShell)**
```sh
[System.Environment]::SetEnvironmentVariable("DISCORD_BOT_TOKEN", "your-bot-token-here", [System.EnvironmentVariableTarget]::User)
```
Then restart your terminal.

#### **On Windows (Command Prompt)**
```sh
setx DISCORD_BOT_TOKEN "your-bot-token-here"
```
Then restart your terminal.

#### **On Linux/macOS**
```sh
export DISCORD_BOT_TOKEN="your-bot-token-here"
```

## **Handling Visual Studio Warnings (C4251)**

When compiling with **DPP as a DLL**, you may see warnings like:

```
warning C4251: 'std::string' needs to have dll-interface to be used by clients of 'dpp::user'
```

These warnings are harmless but can be suppressed.

### **Option 1: Disable Warnings in Visual Studio (Recommended)**
1. **Open Visual Studio**.
2. **Right-click the project > Properties**.
3. Go to **C/C++ > Command Line**.
4. Add this to **Additional Options**:
   ```
   /wd4251
   ```
5. Click **OK**, then **Apply**.

### **Option 2: Use a Static DPP Build**
If you don’t want to use DPP as a DLL, install the static version:

```sh
vcpkg install dpp:x64-windows-static
```

Then, set your **Runtime Library** to **Multi-threaded (`/MT`)** in Visual Studio:
1. **Go to Project Properties**.
2. **Navigate to C/C++ > Code Generation**.
3. Set **Runtime Library** to:
   - **Multi-threaded (`/MT`)** for Release.
   - **Multi-threaded Debug (`/MTd`)** for Debug.
4. Click **OK**, then **Apply**.

## **Building and Running**
Once everything is set up, build the project in **Visual Studio 2022**, and run the bot.

```sh
./AstroBot.exe
```

Your bot should now be online and running in your Discord server!

