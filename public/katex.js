const katexHTML = document.getElementsByClassName('katex-html')

console.log(katexHTML)

katexHTML.forEach((elem) => {
  elem.style.setAttribute('display', 'none')
})
