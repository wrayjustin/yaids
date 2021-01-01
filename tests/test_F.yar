rule test_F_01 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_F_01 (Wildcard, Expected: 21)"
        more_info = "https://yaids.io"
    strings:
        $string1 = { ?? }
    condition:
        any of them
}