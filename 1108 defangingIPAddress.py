class Solution:
    def defangIPaddr(self, address: str) -> str:
        # adressSplit = address.split('.');
        # res = adressSplit[0] + '[.]'+ adressSplit[1] + '[.]'+ adressSplit[2] + '[.]'+ adressSplit[3]
        # return res
        return address.replace('.', '[.]')