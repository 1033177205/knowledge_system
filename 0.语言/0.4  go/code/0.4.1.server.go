package main

import (
	"fmt"
	"net"
)

func process(conn net.Conn) {
	defer conn.Close()

	for {
		buff := make([]byte, 1024)

		n, err := conn.Read(buff)  //内部有锁机制保证安全

		if err != nil {
			fmt.Println("接收数据错误，err=%v", err)
			return 
		}

		fmt.Println("接收数据：%v", string(buff[:n]))
	}
}

func main() {
	fmt.Println("第一个服务器 ")

	listen, err := net.Listen("tcp", "0.0.0.0:8080")

	if err != nil {
		fmt.Println("监听失败，er=", err)
		return 
	}

	 defer listen.Close();

	 for {
			fmt.Println("等待连接 ")
			conn, err := listen.Accept()
			if err != nil {
				fmt.Println("accept error，err=", err)
			} else {
				fmt.Println("accept succse con=%v, 客户端ip=%v\n", conn, conn.RemoteAddr().String())
			}

			//开启协程
			go process(conn)
	 }
}