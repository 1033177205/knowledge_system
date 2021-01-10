package main

import (
	"fmt"
	"net"
	"bufio"
	"os"
	"strings"
)


func main() {
	fmt.Println("第一个客户端 ")

	conn, err := net.Dial("tcp", "127.0.0.1:8080")

	if err != nil {
		fmt.Println("连接失败，er=", err)
		return 
	}

	defer conn.Close();
	reader := bufio.NewReader(os.Stdin)		//读取命令行的数据
	for {
			line, err := reader.ReadString('\n')	//以\n分割字符串
			if err != nil {
				fmt.Println("ReadString，er=", err)
			}

			line = strings.Trim(line, "\r\n")			//去掉line中的\r\n
		
			if line == "exit" {
				fmt.Println("客户端退出")
				break
			}

			n, err := conn.Write([]byte(line))
			if err != nil {
				fmt.Println("Write=", err)
			}
			fmt.Println("写成功字节n=%v", n)
	 }
}