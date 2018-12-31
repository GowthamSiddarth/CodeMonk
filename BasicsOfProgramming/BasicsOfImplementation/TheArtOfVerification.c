/**
Cleartrip decided that they wanted to verify the username and password of its
users while they were authenticating for a process. One of the code service
forms a GET URL which contains the username and password as its parameters.
While parsing the URL, the code needs to extract the key-value pairs of ALL the
parameters passed in the request URL which may contains '&' or/and '='.

The string can contain any type of alphabetical, numeric and special characters
in the URL.

Input format:
A valid Cleartrip link.

Output format:
Print the following:
username: From the URL.
pwd: From the URL.
profile: From the URL.
role: From the URL.
key: From the URL.

Constraints:
1 <= |Length of the URL| <= 1000

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/the-art-of-verification/
*/
#include <string.h>
#include <stdio.h>

struct URLParsed {
    char username[101], pwd[101], profile[101], role[101], key[101];
};

int indexOf(char *string, char c, int start) {
    int idx = start;
    while ('\0' != string[idx] && c != string[idx]) {
        idx++;
    }

    return '\0' == string[idx] ? -1 : idx;
}

void stringcpy(char *src, char *dest, int startSrc, int startDest, int numOfChars) {
    int itr = 0;
    while (itr < numOfChars) {
        dest[startDest + itr] = src[startSrc + itr];
        itr++;
    }
    dest[itr] = '\0';
}

struct URLParsed parseURL(char *url) {
    struct URLParsed urlParsed;
    int start, nextStartSignIdx, nextEndSignIdx;
    
    start = 0;
    nextStartSignIdx = indexOf(url, '=', start);
    nextEndSignIdx = indexOf(url, '&', start);    
    stringcpy(url, urlParsed.username, nextStartSignIdx + 1, 0, nextEndSignIdx - nextStartSignIdx - 1);

    start = nextEndSignIdx + 1;
    nextStartSignIdx = indexOf(url, '=', start);
    nextEndSignIdx = indexOf(url, '&', start);
    stringcpy(url, urlParsed.pwd, nextStartSignIdx + 1, 0, nextEndSignIdx - nextStartSignIdx - 1);

    start = nextEndSignIdx + 1;
    nextStartSignIdx = indexOf(url, '=', start);
    nextEndSignIdx = indexOf(url, '&', start);
    stringcpy(url, urlParsed.profile, nextStartSignIdx + 1, 0, nextEndSignIdx - nextStartSignIdx - 1);

    start = nextEndSignIdx + 1;
    nextStartSignIdx = indexOf(url, '=', start);
    nextEndSignIdx = indexOf(url, '&', start);    
    stringcpy(url, urlParsed.role, nextStartSignIdx + 1, 0, nextEndSignIdx - nextStartSignIdx - 1);

    start = nextEndSignIdx + 1;
    nextStartSignIdx = indexOf(url, '=', start);
    nextEndSignIdx = strlen(url);    
    stringcpy(url, urlParsed.key, nextStartSignIdx + 1, 0, nextEndSignIdx - nextStartSignIdx - 1);

    return urlParsed;
}

void printParsedURL(struct URLParsed urlParsed) {
    printf("username: %s\n", urlParsed.username);
    printf("pwd: %s\n", urlParsed.pwd);
    printf("profile: %s\n", urlParsed.profile);
    printf("role: %s\n", urlParsed.role);
    printf("key: %s\n", urlParsed.key);
}

int main() {
    char url[1001];
    memcpy(url, "http://www.cleartrip.com/signin/service?username=test&pwd=test&profile=developer&role=ELITE&key=manager", 104);

    struct URLParsed urlParsed = parseURL(url);
    printParsedURL(urlParsed);

    return 0;
}