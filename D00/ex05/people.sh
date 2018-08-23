ldapsearch -Q -LLL uid='z*' | grep "cn:" | cut -c5- | sort -r | grep z -i


