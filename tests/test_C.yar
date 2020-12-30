rule test_C_01 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (DNS Request, Expected: 1)"
        more_info = "https://yaids.io"
    strings:
        $string1 = "armless Nessus echo test"
    condition:
        //$string1 in ((int8(0) + 255) + 4)
        any of them
}
