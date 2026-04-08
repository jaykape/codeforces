n = gets.to_i

if n % 2 == 0
  k = n / 2
  puts k
  puts ([2] * k).join(" ")
else
  k = (n - 3) / 2 + 1
  puts k
  puts ([2] * ((n - 3) / 2) + [3]).join(" ")
end