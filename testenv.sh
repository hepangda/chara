sudo iptables -t nat -A OUTPUT -d localhost -p tcp --dport 53 -j REDIRECT --to-port 8053
sudo iptables -t nat -A OUTPUT -d localhost -p udp --dport 53 -j REDIRECT --to-port 8053