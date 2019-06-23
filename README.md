Introduction
============

This project aims to provide an implementation of WaTor, see https://en.wikipedia.org/wiki/Wa-Tor . It aims to be runable with with the QT webassembly target.

Building
========

Just run
```
qmake
make
```

Licensing
=========

The code is Copyright 2019 by Florian Schmitt and is licensed under the GNU GPLv3. For details see `COPYING` or https://www.gnu.org/licenses/gpl-3.0.html .

The graphics are Copyright 2019 by Twitter, Inc and other contributors  and are licensed under CC-BY 4.0. See LICENSE-GRAPHICS or https://creativecommons.org/licenses/by/4.0/ .
They have been taken from the [Twemoji project](https://twemoji.twitter.com/). For more details see also 
images/twemoji/README.txt .

If you plan to run on webassembly, use at least a stripped down Qt library. There may be licensing issues lurking when putting the
resulting binary on a public server. See: https://github.com/desperadoduck/qwator/issues/1 . 
At the moment, there is no final recommendation on how to avoid these issues, so you should check for yourself, if every requirement is fulfilled (and ideally document that in the issue, so that everybody can learn from that).
