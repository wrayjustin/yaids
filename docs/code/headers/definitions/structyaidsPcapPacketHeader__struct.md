---
title: structyaidsPcapPacketHeader__struct
permalink: code/headers/definitions/structyaidsPcapPacketHeader__struct
---
# structyaidsPcapPacketHeader__struct

<table>
<colgroup>
<col style="width: 50%" />
<col style="width: 50%" />
</colgroup>
<tbody>
<tr class="odd">
<td><img src="/yaids.png" alt="Logo" /></td>
<td><div id="projectname">
YAIDS
</div></td>
</tr>
</tbody>
</table>


yaidsPcapPacketHeader\_struct Struct Reference

`#include <yaidstypes.h>`

<span id="pub-attribs"></span> Public Attributes
------------------------------------------------

bool 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#a1eb6d3ff0f0b6a17206f3790ac48751e" class="el">frameExists</a>

 

bool 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#a03a59b5bbd51365fccea371c8f5a6209" class="el">netExists</a>

 

bool 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#a262ab103da05f97d282fca14c83d7d07" class="el">transportExists</a>

 

char 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#ace396f150126aef822259d76eae35e70" class="el">typeList</a>
\[42\]

 

char 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#aea4090f861164b267a547910bc0cacf6" class="el">frameType</a>
\[14\]

 

char 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#affb9f2b09b4ca1de57f323fffb5ed9da" class="el">frameSource</a>
\[INET6\_ADDRSTRLEN+1\]

 

char 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#ae45b0bfef86df33de0e7868720634cc0" class="el">frameDest</a>
\[INET6\_ADDRSTRLEN+1\]

 

char 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#a70d08c50adf6abcfa2d23105177dbae3" class="el">netType</a>
\[14\]

 

char 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#a9a937a456a0a49f7887ea7a0c65bc919" class="el">netSource</a>
\[INET6\_ADDRSTRLEN+1\]

 

char 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#ae70ed4e472e51821b92c6e06a9a35330" class="el">netDest</a>
\[INET6\_ADDRSTRLEN+1\]

 

char 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#ac08d98467749b4e020ef1c5b801a29e9" class="el">transportType</a>
\[14\]

 

char 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#a9b943ef44889263505df65e7f22d4c6a" class="el">transportSource</a>
\[10\]

 

char 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#a4f75f0475154379d2489fc549bed78c0" class="el">transportDest</a>
\[10\]

 

int 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#a5fe9ed31438a004bdc077f226c0b12ae" class="el">payloadOffset</a>

 

int 

<a href="/code/headers/definitions/structyaidsPcapPacketHeader__struct#a725b119e108a7496750cc0029eb70818" class="el">originalPacketLength</a>

 

Member Data Documentation
-------------------------

<span id="ae45b0bfef86df33de0e7868720634cc0"></span>

<span class="permalink">[◆ ](#ae45b0bfef86df33de0e7868720634cc0)</span>frameDest
--------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char yaidsPcapPacketHeader_struct::frameDest[INET6_ADDRSTRLEN+1]</td>
</tr>
</tbody>
</table>

<span id="a1eb6d3ff0f0b6a17206f3790ac48751e"></span>

<span class="permalink">[◆ ](#a1eb6d3ff0f0b6a17206f3790ac48751e)</span>frameExists
----------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>bool yaidsPcapPacketHeader_struct::frameExists</td>
</tr>
</tbody>
</table>

<span id="affb9f2b09b4ca1de57f323fffb5ed9da"></span>

<span class="permalink">[◆ ](#affb9f2b09b4ca1de57f323fffb5ed9da)</span>frameSource
----------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char yaidsPcapPacketHeader_struct::frameSource[INET6_ADDRSTRLEN+1]</td>
</tr>
</tbody>
</table>

<span id="aea4090f861164b267a547910bc0cacf6"></span>

<span class="permalink">[◆ ](#aea4090f861164b267a547910bc0cacf6)</span>frameType
--------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char yaidsPcapPacketHeader_struct::frameType[14]</td>
</tr>
</tbody>
</table>

<span id="ae70ed4e472e51821b92c6e06a9a35330"></span>

<span class="permalink">[◆ ](#ae70ed4e472e51821b92c6e06a9a35330)</span>netDest
------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char yaidsPcapPacketHeader_struct::netDest[INET6_ADDRSTRLEN+1]</td>
</tr>
</tbody>
</table>

<span id="a03a59b5bbd51365fccea371c8f5a6209"></span>

<span class="permalink">[◆ ](#a03a59b5bbd51365fccea371c8f5a6209)</span>netExists
--------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>bool yaidsPcapPacketHeader_struct::netExists</td>
</tr>
</tbody>
</table>

<span id="a9a937a456a0a49f7887ea7a0c65bc919"></span>

<span class="permalink">[◆ ](#a9a937a456a0a49f7887ea7a0c65bc919)</span>netSource
--------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char yaidsPcapPacketHeader_struct::netSource[INET6_ADDRSTRLEN+1]</td>
</tr>
</tbody>
</table>

<span id="a70d08c50adf6abcfa2d23105177dbae3"></span>

<span class="permalink">[◆ ](#a70d08c50adf6abcfa2d23105177dbae3)</span>netType
------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char yaidsPcapPacketHeader_struct::netType[14]</td>
</tr>
</tbody>
</table>

<span id="a725b119e108a7496750cc0029eb70818"></span>

<span class="permalink">[◆ ](#a725b119e108a7496750cc0029eb70818)</span>originalPacketLength
-------------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsPcapPacketHeader_struct::originalPacketLength</td>
</tr>
</tbody>
</table>

<span id="a5fe9ed31438a004bdc077f226c0b12ae"></span>

<span class="permalink">[◆ ](#a5fe9ed31438a004bdc077f226c0b12ae)</span>payloadOffset
------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>int yaidsPcapPacketHeader_struct::payloadOffset</td>
</tr>
</tbody>
</table>

<span id="a4f75f0475154379d2489fc549bed78c0"></span>

<span class="permalink">[◆ ](#a4f75f0475154379d2489fc549bed78c0)</span>transportDest
------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char yaidsPcapPacketHeader_struct::transportDest[10]</td>
</tr>
</tbody>
</table>

<span id="a262ab103da05f97d282fca14c83d7d07"></span>

<span class="permalink">[◆ ](#a262ab103da05f97d282fca14c83d7d07)</span>transportExists
--------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>bool yaidsPcapPacketHeader_struct::transportExists</td>
</tr>
</tbody>
</table>

<span id="a9b943ef44889263505df65e7f22d4c6a"></span>

<span class="permalink">[◆ ](#a9b943ef44889263505df65e7f22d4c6a)</span>transportSource
--------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char yaidsPcapPacketHeader_struct::transportSource[10]</td>
</tr>
</tbody>
</table>

<span id="ac08d98467749b4e020ef1c5b801a29e9"></span>

<span class="permalink">[◆ ](#ac08d98467749b4e020ef1c5b801a29e9)</span>transportType
------------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char yaidsPcapPacketHeader_struct::transportType[14]</td>
</tr>
</tbody>
</table>

<span id="ace396f150126aef822259d76eae35e70"></span>

<span class="permalink">[◆ ](#ace396f150126aef822259d76eae35e70)</span>typeList
-------------------------------------------------------------------------------

<table>
<tbody>
<tr class="odd">
<td>char yaidsPcapPacketHeader_struct::typeList[42]</td>
</tr>
</tbody>
</table>

------------------------------------------------------------------------

The documentation for this struct was generated from the following file:

-   include/<a href="/code/headers/yaidstypes" class="el">yaidstypes.h</a>

------------------------------------------------------------------------

<span class="small">Source Code Documentation Generated By `doxygen`</span>  
