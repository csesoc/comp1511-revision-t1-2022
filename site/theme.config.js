import Logo from './components/Logo'

export default {
  github: 'https://github.com/csesoc/comp1511-revision-2022',
  docsRepositoryBase: 'https://github.com/csesoc/comp1511-revision-2022',
  titleSuffix: ' – CSESoc ',
  logo: (
    <>
      <Logo />
      <div className='px-4 text-gray-600 font-normal hidden md:inline'>
        COMP1511 Prep 'n' Chill (T1, 2022)
      </div>
    </>
  ),
  head: (
    <>
      <meta name='msapplication-TileColor' content='#ffffff' />
      <meta name='theme-color' content='#ffffff' />
      <meta name='viewport' content='width=device-width, initial-scale=1.0' />
      <meta httpEquiv='Content-Language' content='en' />
      <meta
        name='description'
        content="COMP1511 Prep 'n' Chill (T1, 2022)"
      />
      <meta
        name='og:description'
        content='Questions with solutions + explanations, sample code and more.'
      />
      <meta name='twitter:card' content='summary_large_image' />
      <meta
        name='twitter:image'
        content='https://comp1511-revision-t1-2022.vercel.app/og.png'
      />
      <meta
        name='twitter:site:domain'
        content='https://comp1511-revision-t1-2022.vercel.app'
      />
      <meta
        name='twitter:url'
        content='https://comp1511-revision-t1-2022.vercel.app'
      />
      <meta name='og:title' content="COMP1511 Revision Session '22" />
      <meta
        name='og:image'
        content='https://comp1511-revision-t1-2022.vercel.app/og.png'
      />
      <meta name='apple-mobile-web-app-title' content='COMP1511' />
      <link
        rel='apple-touch-icon'
        sizes='180x180'
        href='/apple-icon-180x180.png'
      />
      <link
        rel='icon'
        type='image/png'
        sizes='192x192'
        href='/android-icon-192x192.png'
      />
      <link
        rel='icon'
        type='image/png'
        sizes='32x32'
        href='/favicon-32x32.png'
      />
      <link
        rel='icon'
        type='image/png'
        sizes='96x96'
        href='/favicon-96x96.png'
      />
      <link
        rel='icon'
        type='image/png'
        sizes='16x16'
        href='/favicon-16x16.png'
      />
      <meta name='msapplication-TileImage' content='/ms-icon-144x144.png' />
    </>
  ),
  search: true,
  prevLinks: true,
  nextLinks: true,
  footer: true,
  footerEditLink: 'Edit this page on GitHub',
  footerText: <>MIT {new Date().getFullYear()} © UNSW CSESoc.</>,
  unstable_faviconGlyph: '💻'
}
