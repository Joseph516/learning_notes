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

### concept
- 工作区/版本库（包括暂存区和分支）
- stage: temporary storage.暂存区。
- branch: incuding master, and others 分支.

