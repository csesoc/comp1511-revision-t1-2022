# COMP1511 Prep 'n' Chill (T1, 2022) website

This site hosts the solutions, explanations and sample code to the questions from the COMP1511 Exam Prep 'n Chill event run on the 27th of March, 2022.

## Prerequisites

Before you start, make sure you have the following installed:

- Git and [GitHub CLI](https://cli.github.com)
- Node.js, npm and yarn

## Setup

Clone the repository:
`gh repo clone csesoc/comp1511-revision-t1-2022`

## Running the site locally

1. Navigate into `/comp1511-revision-t1-2022/site`
2. Install packages with `yarn install`
3. You're good to go! Run `yarn next` to start the dev server.
4. The site can now be viewed at `http://localhost:3000`.

Any changes you make to the codebase will be reflected on the page instantly on save (i.e. writing solutions).

## Formatting and linting

Prettier and Standard JS are used for formatting and linting. The VS Code workspace has been configured with the relevant extensions. When you open `/comp1511-revision-t1-2022` in VS Code, a recommendation notification should pop up - click Install. If this doesn't show up, open the command palette and type 'Show Recommended Extensions'.

Once the extensions are installed, open the command palette, type 'Format Document With' and make sure it's set to prettier-standard.

## Documentation

See [contributing.md](contributing.md).
