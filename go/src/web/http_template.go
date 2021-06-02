package main

import (
	"fmt"
	"log"
	"net/http"
	"strconv"
	"text/template"
)

func main() {
	http.HandleFunc("/", tempFunc)
	// http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
	// 	w.Write([]byte(r.URL.Query().Get("val")))
	// })
	http.HandleFunc("/2", tempFunc2)

	log.Println("Starting HTTP server...")
	log.Fatal(http.ListenAndServe("localhost:4000", nil))
}

// curl http://localhost:4000/?val=666
func tempFunc(w http.ResponseWriter, r *http.Request) {
	// 创建模板对象并解析模板内容
	tmpl, err := template.New("test").Parse("The value is {{.}}") // 点操作符默认指向的是根对象
	if err != nil {
		fmt.Fprintf(w, "Parse: %v", err)
		return
	}
	// 从URL获取参数值
	val := r.URL.Query().Get("val")

	// 调用模板对象的渲染方法
	err = tmpl.Execute(w, val)
	if err != nil {
		fmt.Fprintf(w, "Execute: %v", err)
		return
	}
}

type Inventory struct {
	SKU       string
	Name      string
	UnitPrice float64
	Quantity  int64
}

// curl http://localhost:4000/2?sku=1122334&name=phone&unitPrice=649.99&quantity=833
func tempFunc2(w http.ResponseWriter, r *http.Request) {
	// 创建模板对象并解析模板内容
	tmpl, err := template.New("test").Parse(`{{/*这是注释行*/}}
Inventory
SKU: {{.SKU}}
Name: {{.Name}}
UnitPrice: {{.UnitPrice}}
Quantity: {{.Quantity}}
`)
	if err != nil {
		fmt.Fprintf(w, "Parse: %v", err)
		return
	}

	// 根据 URL 查询参数的值创建 Inventory 实例
	inventory := &Inventory{
		SKU:  r.URL.Query().Get("sku"),
		Name: r.URL.Query().Get("name"),
	}

	// 注意：为了简化代码逻辑，这里并没有进行错误处理
	inventory.UnitPrice, _ = strconv.ParseFloat(r.URL.Query().Get("unitPrice"), 64)
	inventory.Quantity, _ = strconv.ParseInt(r.URL.Query().Get("quantity"), 10, 64)

	// 调用模板对象的渲染方法
	err = tmpl.Execute(w, inventory)
	if err != nil {
		fmt.Fprintf(w, "Execute: %v", err)
		return
	}
}
