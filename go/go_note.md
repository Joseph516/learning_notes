# Golang

## web

[无闻 golang web 教学](https://studygolang.com/subject/479)

## gopath

gopath 设置：`go env -w GOPATH=path to you project`

当前 workspace 目录：

```shell
$ hyh in ~/developer/chat λ tree . -L 2
├── bin
│   ├── chat
│   ├── dlv
│   ├── dlv-dap
│   ├── go-outline
│   ├── gopkgs
│   ├── gopls
│   └── staticcheck
├── pkg  # dependecy packages
│   ├── mod
│   └── sumdb
└── src  # source code with go.mod
    ├── go.mod
    ├── go.sum
    ├── main.go
    └── utils  # your other codes
```

### 常用命令

```shell
# init go.mod in your src
cd src
go mod init <your developement>


# download some dependencies in your source codes
go mod tidy

# clean mod dependencies cache
go clean -modcache

# install developement and generate binary executions to bin folder
cd src
go install <your developement>

# execute your developnment
cd bin
./<your developement>
```
