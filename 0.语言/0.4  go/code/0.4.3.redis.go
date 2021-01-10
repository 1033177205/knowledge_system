package main

import (
	"fmt"
	"github.com/gomodule/redigo/redis"
)


func main() {
	fmt.Println("redis操作 ")

	c, err := redis.Dial("tcp", "192.168.0.107:6379")
	if err != nil {
		fmt.Println("连接超时 ")
		return
	}

	

	defer c.Close()
}