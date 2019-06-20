# ft_ssl_md5
recreating md5, sha256 and sha 224 algorithms


## Project
FT_SSL_MD5 is a 42 Project that mimics libc ls function

* Basic functions:
1) md5, sha256

* Flags:
1) -s, -q, -r -p

* Bonus:
1) sha224

## Sources
* https://en.wikipedia.org/wiki/SHA-2
* https://en.wikipedia.org/wiki/MD5
* https://csrc.nist.gov/csrc/media/publications/fips/180/4/final/documents/fips180-4-draft-aug2014.pdf

## Installation
```
$> make
$> ./ft_ssl_md5 {hash_function} {flag} {file}
$> works with stdin too:
$> 1)./ft_ssl_md5 {hash_function} 
$> 2) Hit Enter, enter text, ctrl + d to output
```
