# VIM

## 安装插件

### 插件管理器

[vim-plug](https://github.com/junegunn/vim-plug)

- 安装插件

  修改 `~/.vimrc`文件并重载 (`:source ~/.vimrc`) or restart Vim. 

  Run `:PlugInstall` to install the plugins.

- 插件更新

  Run `:PlugUpdate` to update the plugins. After the update is finished, you can review the changes by pressing `D` in the window. Or you can do it later by running `:PlugDiff`

- 移除插件

  1.移除`Plug` 命令中不需要的插件.

  2.Reload vimrc (`:source ~/.vimrc`) or restart Vim

  3.Run `:PlugClean`. 会自动检测并清楚不在声明内的插件.
### 主要插件 

- [YouCompleteMe](https://github.com/Valloric/YouCompleteMe)：代码补全。

- [fzf](https://github.com/junegunn/fzf.vim)：模糊搜索工具，可以用GFiles查看git文件变化。或搭配The Silver Searcher使用Ag。

- [vim-audoformat](https://github.com/chiel92/vim-autoformat)：代码风格整理。

  将clang-format设置未全局格式。
  let g:formatterpath = ['/home/joe', '/home/joe/.clang-format']

- [vim-airline](https://github.com/vim-airline/vim-airline)：vim状态栏可视化。

- rainbow.：彩虹括号

- auto-pairs：自动补充括号

- nerdtree：文件目录显示。

## 基本操作

### 设置缩进Indent

- set tabstop=8  //设置缩进, 注意不要有空格。
- set expantab
- set shiftwidth=2 // 缩进2个空格
- set autoindent // 自动缩进
- set cindent // stricter rules for cprograms
- set nu // 显示行号
- set nonu // 取消显示行号

