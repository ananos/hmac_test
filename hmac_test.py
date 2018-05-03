
from hashlib import sha512,sha256,sha1
import hmac
import sys

def sign_request(message, key, shaVar):

    hashed = hmac.new(key, message, shaVar)

    # The signature
    return hashed.digest().encode("hex")


def main():
    try:
        message = sys.argv[1]
        key = sys.argv[2]
        shaVar = sys.argv[3]
    except:
        print("You need to specify the message, key and sha variant")
        return

    signature = sign_request(message, key, eval(shaVar))
    print(signature)


if __name__ == '__main__':
    main()

