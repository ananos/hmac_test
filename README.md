== HMAC_test based on sha1, sha256, sha384 and sha512 ==

hmac_test is a simple program that generates the hmac of a message based on
different sha variants. I put it together to understand how HMAC works. Most of
the sha implementation logic is copied from https://github.com/Yubico/yubico-c-client.


=== Building ===

After downloading and unpacking the package tarball or cloning the repo, you build it as
follows:

    make


=== Example usage ===

    $ ./hmac_test "This is my message" "My secret key"
    6baef89c930c98bef15e1a371e39e18d10542bc21868bc5912ab90bf000b3dbe


    $ python hmac_test.py "This is my message" "My secret key" sha256
    6baef89c930c98bef15e1a371e39e18d10542bc21868bc5912ab90bf000b3dbe

=== License ===

The project is licensed under a BSD license.  See the file COPYING for
exact wording.  

