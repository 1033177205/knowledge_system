package main

import (
	"fmt"
	"net/http"
)

func sayHello(w http.ResponseWriter, r *http.Request) {
	_, _ = w.Write([]byte("haha") )
}

func main() {
	fmt.Println("http服务器 ")

	http.HandleFunc("/", sayHello)

	err := http.ListenAndServe("127.0.0.1:90", nil)
	if err != nil {
		fmt.Println("ListenAndServer  error")
	}
}