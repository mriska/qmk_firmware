# The default keymap for kbd4x

```
make git-submodule
make kbdfans/kbd4x:mriska
make kbdfans/kbd4x:mriska:dfu
```

```
git co master
git fetch -p upstream
git merge upstream/master --ff-only
git push
git co mriska
git rebase origin/master
git push -f
```
