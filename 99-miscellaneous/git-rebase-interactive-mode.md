# git rebase -i

## 개요 
- 브랜치에 이미 올라가 있는 커밋 여러 개를 하나의 커밋으로 squash 해야 할 일이 있을 때 사용하면 좋은 전략
- `git rebase` 란? 생성된 커밋들을 특정 브랜치의 HEAD 에 올리는 작업
	> Reapply commits on top of another base tip 
- `-i (--interactive)` 명령어는? reabse 대상이 되는 커밋들을 리스팅 하고, 편집할 수 있도록 해 주는 명령어. 

## interactive mode
- `rebase -i <after-this-commit>` 입력 시 rebase 대상이 되는 커밋들이 나열되며, 편집할 수 있는 vi 창이 뜸 (여기서 `<after-this-commit>` 은, rebase 대상이 될 커밋들의 시작점임)
- 예시
```
pick deadbee The oneline of this commit
pick fa1afe1 The oneline of the next commit
```
디폴트로 모든 커밋 앞에 `pick` 이 붙는데, 아래 다양한 옵션으로 수정할 수 있음 
- `pick` : 해당 커밋을 사용
- `reword` : 해당 커밋을 사용하되, 커밋명을 수정
- `edit` : 해당 커밋을 사용하되, 수정해야 함
- `squash` : 해당 커밋을 사용하되, 이전 커밋으로 squash (합치기)
- `fixup` : `squash` 와 비슷하지만 이전 커밋 로그 메세지를 보존
- `drop` : 해당 커밋 삭제
- `merge` : 해당 커밋 메세지를 사용하여 merge commit 명 생성 
- 등...

### other tips
- Git log 를 볼 때 `log --oneline --graph --decorate --all` 명령어를 사용하면, 전체 깃 그래프를 볼 수 있음 

### 참고자료
- [공식문서](https://git-scm.com/docs/git-rebase#_interactive_mode)