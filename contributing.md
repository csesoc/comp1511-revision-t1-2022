# Contributing

Let's get up to speed quickly!

## Getting started

First, make sure your version of the repo is up to date. Run

```
git pull origin master
```

Then, create a branch and push it to the repo. This allows you to isolate your work from the main branch. Pick a branch name that reflects the question/s you're writing a solution for.

```bash
git checkout -b branch-name
git add -A
git push origin branch-name
```

You can now make edits and push commits safely.

## Writing a solution

Navigate to `comp1511-revision-t1-2022` and run `yarn next` to run the site locally. You can now preview changes live.

The `template` folder in `/questions` contains three MDX template files.

- `problem.mdx`: Your problem.
- `approach.mdx`: An explanation of your approach to the problem.
- `code.mdx`: The full sample code for your solution.

Duplicate the `template` folder and rename it according to the question name you're writing a solution for. The sidebar name reflects the folder name which isn't what you want (i.e. `example-question` displays as Example-Question), so let's override this. Go to `meta.json` **in the root of** `questions`, not inside your template folder. It'll look like this:

```json
{
  "TEMPLATE": "Template",
  "folder-name": "actual-name"
  // You need to add your folder here.
}
```

Add your folder name and the name you want instead, then save:

```json
{
  "TEMPLATE": "Template",
  "folder-name": "actual-name",
  "example-question": "Example Question"
}
```

The name you entered should now display properly.

### Writing with Markdown

The pages are written using extended Markdown syntax. The template files provide a quick overview of what you need to get started. For a quick reference to the syntax, look here:

- [Basic Syntax](https://www.markdownguide.org/basic-syntax/)
- [Extended Syntax](Tables, code blocks, etc.)

Something to keep in mind is that to start a new line, you need to type two spaces at the end of your current one before hitting `Enter`.

LaTex support has also been added. Look at `problem.mdx` to see how to write LaTex in your page. If your usual syntax doesn't work, that's because the site uses KaTex to render math, essentially a subset of LaTex - see [here](https://katex.org/docs/supported.html) for the supported syntax.

### Other things

Feel free to save as you go by pushing commits to your branch!

```bash
// Add everything you've been working on
git add -A
// Push it.
git push origin branch-name
```

### Once you're done

Double-check your spelling, grammar and code to make sure everything's right, then push your latest changes and open a pull request.

```bash
gh pr create
```

The pull request will be auto-merged once checks are complete and the site re-deployed on Vercel. You can check it out [here](https://comp1511-revision-t1-2022.vercel.app)!
