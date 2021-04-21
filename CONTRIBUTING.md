## Branches

Use feature branching to contribute to the project. This should keep conflicts to a minimal.

Our branch names will look something like:
* `master`: Branch reflecting the current working verions. Don't commit directly to master. This will be our branch that pull requests are merged to.
Code changes are made in branchs and merged into development using a pull request. Use the following format when naming branches:
    * `feature/some-branch-feature-description`

#General Flow
* When creating a new feature:
1. Pull from master to get latest changes: `git pull origin master`.
2. Create a new branch and switch over to it: `git checkout -b feature/some-branch-feature-description`.
3. Do work on branch. You can view which branch you are on via: `git status`.
4. When you feel your work is complete, you can merge to master.
    * Make sure your branch has the latest master changes: 
    ```
    git checkout origin master
    git pull origin master
    ```
    * Switch back to your feature branch and merge in master. `git merge master`
    * Commit and push changes to github.
    * Open a pull request via GitHub and click merge.

This flow should prevent us from stepping on each others code and keeps all merge conflicts