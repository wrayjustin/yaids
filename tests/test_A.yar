rule test_A_01 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP GET Requests, Expected: 21)"
        more_info = "https://yaids.io"
    strings:
        $string1 = "GET"
    condition:
        $string1 at (int8(0) + 255)
}

rule test_A_02 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP HEAD Requests, Expected: 1)"
        more_info = "https://yaids.io"
    strings:
        $string1 = "HEAD"
    condition:
        $string1 at (int8(0) + 255)
}

rule test_A_03 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP Specific GET Requests, Expected: 3)"
        more_info = "https://yaids.io"
    strings:
        $string1 = "GET /admin"
        $string2 = "GET /phpmyadmin"
    condition:
        for any of them : ( $ at (int8(0) + 255) )
}

rule test_A_04 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP NMAP User Agents, Expected: 3)"
        more_info = "https://yaids.io"
    strings:
        $string1 = "User-Agent: Mozilla/5.0 (compatible; Nmap Scripting Engine; http://nmap.org/book/nse.html)"
    condition:
        $string1 in ((int8(0) + 255)..filesize)
}

rule test_A_05 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP/HTML Hex & Wildcard, Expected: 2)"
        more_info = "https://yaids.io"
    strings:
        $string1 = { 68 72 65 66 3D 22 2F 61 75 2F ?? 2F 31 22 3E 3C 69 6D 67 }
    condition:
        $string1 in ((int8(0) + 255)..filesize)
}

rule test_A_06 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP/HTML Regex & Wildcard, Expected: 12)"
        more_info = "https://yaids.io"
    strings:
        $string1 = /<input type=\".{1,12}\" name=\".{1,20}\" \/>/
    condition:
        $string1 in (309..filesize)
}
