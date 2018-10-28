### command
- git add : add file
- git commit -m "xxx" : commit file with a comment
- git reset --hard HEAD^ : return back to last version.版本库
- git reset --hard HEAD~100 : return back to last 100th version.
- git reset --hard 'commit id': retun to specific version. 
- git reflog: 记录每一次命令。
- git diff HEAD -- file_name: 查看file_name文件工作区与版本库的区别。可以用^查看版本库上一个版本。
- git checkout -- file_name: 撤销工作区的修改。针对没有提交到暂存区的修改。
- git reset HEAD file_name: 撤销暂存版本。
- git rm file_name, then commit: delete 版本库和工作区的文件

### 远程库
- creat ssh key and connect github
- git remote add origin <ssh link>: connect repository.
- git push -u prigin master: push files to origin repository.
- git clone <ssh link>: 克隆，ssh速度较http快

### 分支管理
分支管理可以在原来主线上生成，新生成的分支不影响主线，分支可以随时合并上去，速度极快。
在分支上修改，必须合并之后到master，才能在master上体现。
- git checkout -b <branch>: 新建分区并切换。
- git branch <branch>: 新建分区。
- git checkout <branch>: 切换分区。
- git branch: 查看所有分区。
- git merge <branch>: 合并分支。
- git branch -d <branch>: 删除分支。


### concept
- 工作区/版本库（包括暂存区和分支）
- stage: temporary storage.暂存区。
- branch: incuding master, and others 分支.
- origin: github repository name, which can be modified.
