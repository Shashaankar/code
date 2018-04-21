#!/bin/sh

echo "user:$USER"
echo "date:";date
echo "# of users:";who | wc -l
echo "Calendar";cal
exit 0
