package main

import (
	"log"
	"net/http"
	"os"
	"os/signal"
	"time"
)

func main() {
	// http.HandleFunc("/", hello)
	// http.Handle("/", &helloHandler{})
	mux := http.NewServeMux()
	mux.Handle("/", &helloHandler{})
	mux.HandleFunc("/timeout", helloTimeOut)

	server := http.Server{
		Addr:         "localhost:4000",
		Handler:      mux,
		WriteTimeout: 2 * time.Second,
	}

	// 优雅的停止
	quit := make(chan os.Signal) // 创建系统信号接收器
	signal.Notify(quit, os.Interrupt)
	go func() {
		<-quit // 阻塞，直到收到os.Interrupt
		if err := server.Close(); err != nil {
			log.Fatal("Close sever:", err)
		}
	}()

	log.Println("Starting HTTP server...")
	// err := http.ListenAndServe("localhost:4000", nil) // 启动HTTP服务器
	// err := http.ListenAndServe("localhost:4000", &helloHandler{}) // 启动HTTP服务器
	err := server.ListenAndServe()

	if err != nil {
		if err == http.ErrServerClosed {
			log.Print("Server closed under request.")
		} else {
			log.Print("Server closed unexpected.")
		}
	}

	if err != nil {
		log.Fatal(err)
	}
}

func hello(w http.ResponseWriter, r *http.Request) {
	w.Write([]byte("hello jojo!"))
}

func helloTimeOut(w http.ResponseWriter, r *http.Request) {
	time.Sleep(2 * time.Second)
	w.Write([]byte("Time Out!"))
}

type helloHandler struct {
}

func (_ *helloHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	w.Write([]byte("hello jojo!"))
}
