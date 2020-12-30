//%c%-14s%-14s%-14s%-17s%-17s%-46s%-5s%-46s%-5s

/*
 * Header Offsets:
 *  Payload Offset: 0
 *  Packet Length (Original): 1
 *  Frame Protocol: 6
 *  Network Protocol: 20
 *  Transport Protocol: 34
 *  Frane Source Address: 48
 *  Frame Destination Address: 65
 *  Network Source Adderess: 82
 *  Transport Source (Port): 128
 *  Network Destination Address: 133
 *  Transport Destination (Port): 179
 */

rule test_D_01 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP GET Requests, Expected: 21)"
        more_info = "https://yaids.io"
    strings:
        $frameProtocol = "ETH"
    condition:
        $frameProtocol at frameProtocol
}

rule test_D_02 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP GET Requests, Expected: 21)"
        more_info = "https://yaids.io"
    strings:
        $frameProtocol = "ETH"
        $netProtocol = "IP"
    condition:
        $frameProtocol at frameProtocol and
        $netProtocol at netProtocol
}

rule test_D_03 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP GET Requests, Expected: 21)"
        more_info = "https://yaids.io"
    strings:
        $frameProtocol = "ETH"
        $netProtocol = "IP"
        $transportProtocol = "TCP"
    condition:
        $frameProtocol at frameProtocol and
        $netProtocol at netProtocol and
        $transportProtocol at transportProtocol
}

rule test_D_04 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP GET Requests, Expected: 21)"
        more_info = "https://yaids.io"
    strings:
        $frameProtocol = "ETH"
        $netProtocol = "IP"
        $transportProtocol = "TCP"
        $frameSource = "00:16:47:9D:F2:C2"
    condition:
        $frameProtocol at frameProtocol and
        $netProtocol at netProtocol and
        $transportProtocol at transportProtocol and
        $frameSource at frameSource
}

rule test_D_05 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP GET Requests, Expected: 21)"
        more_info = "https://yaids.io"
    strings:
        $frameProtocol = "ETH"
        $netProtocol = "IP"
        $transportProtocol = "TCP"
        $frameSource = "00:16:47:9D:F2:C2"
        $frameDest = "00:0C:29:89:D0:73"
    condition:
        $frameProtocol at frameProtocol and
        $netProtocol at netProtocol and
        $transportProtocol at transportProtocol and
        $frameSource at frameSource and
        $frameDest at frameDest
}

rule test_D_06 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP GET Requests, Expected: 21)"
        more_info = "https://yaids.io"
    strings:
        $frameProtocol = "ETH"
        $netProtocol = "IP"
        $transportProtocol = "TCP"
        $frameSource = "00:16:47:9D:F2:C2"
        $frameDest = "00:0C:29:89:D0:73"
        $networkSource = "192.168.21.101"
    condition:
        $frameProtocol at frameProtocol and
        $netProtocol at netProtocol and
        $transportProtocol at transportProtocol and
        $frameSource at frameSource and
        $frameDest at frameDest and
        $networkSource at networkSource
}

rule test_D_07 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP GET Requests, Expected: 21)"
        more_info = "https://yaids.io"
    strings:
        $frameProtocol = "ETH"
        $netProtocol = "IP"
        $transportProtocol = "TCP"
        $frameSource = "00:16:47:9D:F2:C2"
        $frameDest = "00:0C:29:89:D0:73"
        $networkSource = "192.168.21.101"
        $transportSource = "80"
    condition:
        $frameProtocol at frameProtocol and
        $netProtocol at netProtocol and
        $transportProtocol at transportProtocol and
        $frameSource at frameSource and
        $frameDest at frameDest and
        $networkSource at networkSource and
        $transportSource at transportSource
}

rule test_D_08 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP GET Requests, Expected: 21)"
        more_info = "https://yaids.io"
    strings:
        $frameProtocol = "ETH"
        $netProtocol = "IP"
        $transportProtocol = "TCP"
        $frameSource = "00:16:47:9D:F2:C2"
        $frameDest = "00:0C:29:89:D0:73"
        $networkSource = "192.168.21.101"
        $transportSource = "80"
        $networkDest = "192.168.202.90"
    condition:
        $frameProtocol at frameProtocol and
        $netProtocol at netProtocol and
        $transportProtocol at transportProtocol and
        $frameSource at frameSource and
        $frameDest at frameDest and
        $networkSource at networkSource and
        $transportSource at transportSource and
        $networkDest at networkDest
}

rule test_D_09 {
    meta:
        author = "YAIDS.io"
        description = "YAIDS Testing: Test_A_01 (HTTP GET Requests, Expected: 21)"
        more_info = "https://yaids.io"
    strings:
        $frameProtocol = "ETH"
        $netProtocol = "IP"
        $transportProtocol = "TCP"
        $frameSource = "00:16:47:9D:F2:C2"
        $frameDest = "00:0C:29:89:D0:73"
        $networkSource = "192.168.21.101"
        $transportSource = "80"
        $networkDest = "192.168.202.90"
        $transportDest = "33783"
    condition:
        $frameProtocol at frameProtocol and
        $netProtocol at netProtocol and
        $transportProtocol at transportProtocol and
        $frameSource at frameSource and
        $frameDest at frameDest and
        $networkSource at networkSource and
        $transportSource at transportSource and
        $networkDest at networkDest and
        $transportDest at transportDest
}
