## 環境構築について
組込みでのTDDを検討してみるにあたって、以下の条件に沿って環境を選定した。
1. できるだけ組込みに近い構成
2. 身につきやすいようにいつでも使える
3. 誰でも使えるフリーのツールを使う
4. 開発が続いているツールを使う
5. できるだけメジャーなツールを使う
## 開発環境
- OS：Ubuntu 16.04 or 18.04 on WSL (Windows10)
- コンパイラ：gcc/g++
- ビルドツール：make + cmake
- デバッガ：gdb
- エディタ：Visual Studio Code
    - Extensions
        - Remote - WSL
        - C/C++ (in WSL)
        - C++ Intellisense (in WSL)
        - CMake (in WSL)
        - GoogleTest Adapter (in WSL)
- テストフレームワーク：Google Test
- ※各言語関連のツールのシェアを見るのは以下が分かりやすい　⇒　[JET BRAINS](https://www.jetbrains.com/ja-jp/lp/devecosystem-2019/c/)
## 環境構築
### OS のインストール
- [Windows Subsystem for LinuxでUbuntu](https://qiita.com/serlys/items/30f1b43deba257033342)などを参照
    1. 「Windows 機能の有効化または無効化」から「Windows Subsystem for Linux」を有効化する
    2. Ubuntu をインストールする
        - 会社PCの場合はMicrosoft store が無効化されているので、以下の方法でインストール
            1. Windows PowerShell を管理者権限で起動する
            2. 以下の操作でプロキシサーバーの登録と認証を行う
                ```
                > netsh winhttp set proxy proxy-server="address:port"
                > $Wcl=New-Object System.Net.WebClient
                > $Creds=Get-Credential
                > $Wcl.Proxy.Credentials=$Creds
                ```
            3. 以下のコマンドでインストーラーパッケージをダウンロードする
                ```
                > Invoke-WebRequest -Uri https://aka.ms/wsl-ubuntu-1804 -OutFile ~/Ubuntu.appx -UseBasicParsing
                ```
            4. 以下のコマンドで Ubuntu をインストールする
                ```
                > Add-AppxPackage -Path ~/Ubuntu.appx
                ```
    3. Ubuntu コンソールを起動する
        - 起動後、ユーザー名とパスワードの設定を求められるので、自由に設定する
### Ubuntu 側の準備
1. Windows のスタートメニューから Ubuntu コンソールを起動する
2. apt コマンドのプロキシ設定を行う
    ```
    $ sudo vi /etc/apt/apt.conf
    ```
    で設定ファイルを開き、以下を追記
    ```
    Acquire::http::proxy "http://user:pass@addr:port/";
    Acquire::https::proxy "https://user:pass@addr:port/";
    Acquire::ftp::proxy "ftp://user:pass@addr:port/";
    ```
3. 以下の操作で Ubuntu をアップグレードする
    ```
    $ sudo apt update
    $ sudo apt upgrade
    ```
4. C/C++ 開発環境をインストールする
    ```
    $ sudo apt install build-essential
    ```
5. cmake をインストールする
    ```
    $ sudo apt install cmake
    ```
6. gdb をインストールする
    ```
    $ sudo apt install gdb
    ```
7. Google Test をインストールする
    ```
    $ mkdir Download
    $ cd Download
    $ git clone https://github.com/google/googletest.git
    $ cd googleTest
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    $ sudo make install
    ```
    - Ubuntu 16.04 を使用する場合は以下の変更が必要
    - googletest/CMakeList.txt を開く
        - 5行目に以下を追記
            ```
            set(CMAKE_CXX_STANDARD 11)
            ```
        - 13行目を以下のように変更
            ```
            if (CMAKE_VERSION VERSION_GREATER "3.1")
            ```
8. ドライブのマウント設定（必要あれば）
    - Ubuntu をインストールしたドライブ以外は、通常 Ubuntu から見えません
    - 他に使いたいドライブ（例：Dドライブ）がある場合は、ドライブのマウント設定を行います
        1. ドライブのマウントポイントを作成
            ```
            $ sudo mkdir /mnt/d
            $ sudo chown $USER /mnt/d
            $ sudo chgrp $USER /mnt/d
            ```
        2. 設定ファイルを開く
            ```
            $ sudo vi /etc/fstab
            ```
        3. 以下のように追記する
            ```
            D:  /mnt/d  drvfs   default,metadata,uid=1000,gid=1000,umask=022   0   0
            ```
        4. Windows を再起動する
9. Windows ファイルシステムへのシンボリックリンク作成（必要あれば）
    - Ubuntu のユーザーディレクトリは、Windows システムのアプリケーションフォルダの深いところにありアクセスしにくいです
    - そのため、ユーザーディレクトリに、普段使っている作業フォルダのシンボリックリンクを作成することをおすすめします
    - Ubuntu のユーザーディレクトリで、以下のコマンドを実行します
        ```
        $ ln -s /mnt/c/Your/Working/Space ~/Workspace
        ```
### Windows 側の準備
1. Visual Studio Code をダウンロードしてインストールする
    - [VS code Link](https://code.visualstudio.com/download)
2. Extensions をインストールする
    1. 左タブから Extensions を選択し、検索窓で必要な追加機能を検索する
    2. 最初に、「Remote - WSL」をインストールし、VS code を再起動する
    3. 再起動後の VS code のウィンドウの左下に、「open a remote window」のアイコンがあるので、クリックして「Remote-WSL: New Window」コマンドを選択する
    4. Remote-WSL が起動したら、Remote-WSL 側のウィンドウで残りの追加機能をすべてインストールする
### サンプルプロジェクトのビルドと実行
1. VS code を Remote-WSL で起動し、作業ディレクトリを開く
    - VS code を起動した後、左下の「><」アイコンから Remote-WSL を起動する
    - File - Open Folder から作業ディレクトリを選択して開く
2. ターミナルを起動する
    - Terminal - New Terminal でターミナルを起動する
3. GitHub からサンプルプロジェクト取得する
    ```
    $ git clone https://github.com/RyutaroMayumi/TDDSeminar.git
    ```
4. サンプルプロジェクト「ClosedRange」をビルドする
    ```
    $ cd ClosedRange
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    ```
5. テストを実行する
    - VS code の左タブから「Test」を選択し、「Run All」をクリックする
    - または、以下のコマンドで直接実行する
        ```
        TDDSeminar/ClosedRange/build$ ./test/Test
        ```
    - テストが実行され、結果が表示される
