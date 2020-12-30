rule test_B_01 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (FTP 230 Response, Expected: 1)"
        more_info = "https://yaids.io"
    strings:
        $string1 = "Anonymous login ok, send your complete email address as your password"
    condition:
        $string1 at (int8(0) + 255 + 4)
}

rule test_B_02 {
   meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (FTP 220 Response, Expected: 1)"
        more_info = "https://yaids.io"
    strings:
        $string1 = "220-FileZilla Server"
    condition:
        $string1 at (int8(0) + 255)
}

rule test_B_03 {
   meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (FTP 220 Response, Expected: 2)"
        more_info = "https://yaids.io"
    strings:
        $string1 = "USER anonymous"
    condition:
        $string1 at (int8(0) + 255)
}