require 'json'
require 'set'
require 'date'
require 'digest'
require 'base64'
require 'securerandom'

module DataStructures
  class Stack
    def initialize
      @data = []
    end

    def push(item)
      @data.push(item)
      self
    end

    def pop
      @data.pop
    end

    def peek
      @data.last
    end

    def empty?
      @data.empty?
    end

    def size
      @data.size
    end

    def to_a
      @data.dup
    end
  end

  class Queue
    def initialize
      @data = []
    end

    def enqueue(item)
      @data.push(item)
      self
    end

    def dequeue
      @data.shift
    end

    def front
      @data.first
    end

    def empty?
      @data.empty?
    end

    def size
      @data.size
    end
  end

  class LinkedListNode
    attr_accessor :value, :next_node

    def initialize(value, next_node = nil)
      @value = value
      @next_node = next_node
    end
  end

  class LinkedList
    include Enumerable

    def initialize
      @head = nil
      @size = 0
    end

    def prepend(value)
      @head = LinkedListNode.new(value, @head)
      @size += 1
      self
    end

    def append(value)
      if @head.nil?
        @head = LinkedListNode.new(value)
      else
        current = @head
        current = current.next_node until current.next_node.nil?
        current.next_node = LinkedListNode.new(value)
      end
      @size += 1
      self
    end

    def delete(value)
      return if @head.nil?
      if @head.value == value
        @head = @head.next_node
        @size -= 1
        return
      end
      current = @head
      while current.next_node
        if current.next_node.value == value
          current.next_node = current.next_node.next_node
          @size -= 1
          return
        end
        current = current.next_node
      end
    end

    def each
      current = @head
      while current
        yield current.value
        current = current.next_node
      end
    end

    def size
      @size
    end

    def to_a
      result = []
      each { |v| result << v }
      result
    end
  end
end

module Algorithms
  def self.bubble_sort(arr)
    a = arr.dup
    n = a.length
    loop do
      swapped = false
      (n - 1).times do |i|
        if a[i] > a[i + 1]
          a[i], a[i + 1] = a[i + 1], a[i]
          swapped = true
        end
      end
      break unless swapped
    end
    a
  end

  def self.merge_sort(arr)
    return arr if arr.length <= 1
    mid = arr.length / 2
    left = merge_sort(arr[0...mid])
    right = merge_sort(arr[mid..])
    merge(left, right)
  end

  def self.merge(left, right)
    result = []
    until left.empty? || right.empty?
      if left.first <= right.first
        result << left.shift
      else
        result << right.shift
      end
    end
    result + left + right
  end

  def self.binary_search(arr, target)
    low = 0
    high = arr.length - 1
    while low <= high
      mid = (low + high) / 2
      if arr[mid] == target
        return mid
      elsif arr[mid] < target
        low = mid + 1
      else
        high = mid - 1
      end
    end
    -1
  end

  def self.quicksort(arr)
    return arr if arr.length <= 1
    pivot = arr[arr.length / 2]
    left = arr.select { |x| x < pivot }
    middle = arr.select { |x| x == pivot }
    right = arr.select { |x| x > pivot }
    quicksort(left) + middle + quicksort(right)
  end

  def self.fibonacci(n)
    return n if n <= 1
    a, b = 0, 1
    (n - 1).times { a, b = b, a + b }
    b
  end

  def self.factorial(n)
    return 1 if n <= 1
    (2..n).reduce(1, :*)
  end

  def self.prime?(n)
    return false if n < 2
    return true if n == 2
    return false if n.even?
    (3..Math.sqrt(n).to_i).step(2).none? { |i| (n % i).zero? }
  end

  def self.primes_up_to(limit)
    (2..limit).select { |n| prime?(n) }
  end

  def self.gcd(a, b)
    b.zero? ? a : gcd(b, a % b)
  end

  def self.lcm(a, b)
    (a * b).abs / gcd(a, b)
  end
end

class Matrix
  def initialize(rows, cols, default = 0)
    @rows = rows
    @cols = cols
    @data = Array.new(rows) { Array.new(cols, default) }
  end

  def [](r, c)
    @data[r][c]
  end

  def []=(r, c, val)
    @data[r][c] = val
  end

  def +(other)
    result = Matrix.new(@rows, @cols)
    @rows.times do |r|
      @cols.times do |c|
        result[r, c] = self[r, c] + other[r, c]
      end
    end
    result
  end

  def *(other)
    result = Matrix.new(@rows, other.cols)
    @rows.times do |r|
      other.cols.times do |c|
        @cols.times do |k|
          result[r, c] += self[r, k] * other[k, c]
        end
      end
    end
    result
  end

  def transpose
    result = Matrix.new(@cols, @rows)
    @rows.times do |r|
      @cols.times do |c|
        result[c, r] = self[r, c]
      end
    end
    result
  end

  def to_s
    @data.map { |row| row.join("\t") }.join("\n")
  end

  protected

  attr_reader :cols
end

class Graph
  def initialize(directed: false)
    @adjacency = Hash.new { |h, k| h[k] = [] }
    @directed = directed
  end

  def add_edge(u, v, weight: 1)
    @adjacency[u] << { node: v, weight: weight }
    @adjacency[v] << { node: u, weight: weight } unless @directed
  end

  def neighbors(node)
    @adjacency[node]
  end

  def bfs(start)
    visited = Set.new
    queue = [start]
    order = []
    until queue.empty?
      node = queue.shift
      next if visited.include?(node)
      visited.add(node)
      order << node
      @adjacency[node].each { |e| queue << e[:node] unless visited.include?(e[:node]) }
    end
    order
  end

  def dfs(start, visited = Set.new, &block)
    return if visited.include?(start)
    visited.add(start)
    yield start if block_given?
    @adjacency[start].each { |e| dfs(e[:node], visited, &block) }
    visited
  end

  def nodes
    @adjacency.keys
  end
end

module StringUtils
  def self.palindrome?(str)
    clean = str.downcase.gsub(/[^a-z0-9]/, '')
    clean == clean.reverse
  end

  def self.anagram?(a, b)
    a.downcase.chars.sort == b.downcase.chars.sort
  end

  def self.word_count(str)
    str.split.each_with_object(Hash.new(0)) { |w, h| h[w.downcase] += 1 }
  end

  def self.caesar_cipher(str, shift)
    str.chars.map do |c|
      if c =~ /[a-zA-Z]/
        base = c =~ /[a-z]/ ? 'a'.ord : 'A'.ord
        ((c.ord - base + shift) % 26 + base).chr
      else
        c
      end
    end.join
  end

  def self.truncate(str, length, omission: '...')
    return str if str.length <= length
    str[0, length - omission.length] + omission
  end

  def self.slugify(str)
    str.downcase.strip.gsub(/\s+/, '-').gsub(/[^a-z0-9\-]/, '')
  end

  def self.count_vowels(str)
    str.count('aeiouAEIOU')
  end

  def self.reverse_words(str)
    str.split.reverse.join(' ')
  end
end

class Cache
  def initialize(max_size: 100)
    @store = {}
    @access_order = []
    @max_size = max_size
  end

  def get(key)
    return nil unless @store.key?(key)
    @access_order.delete(key)
    @access_order << key
    @store[key]
  end

  def set(key, value)
    if @store.key?(key)
      @access_order.delete(key)
    elsif @store.size >= @max_size
      oldest = @access_order.shift
      @store.delete(oldest)
    end
    @store[key] = value
    @access_order << key
    value
  end

  def delete(key)
    @access_order.delete(key)
    @store.delete(key)
  end

  def size
    @store.size
  end

  def clear
    @store.clear
    @access_order.clear
  end
end

class EventEmitter
  def initialize
    @listeners = Hash.new { |h, k| h[k] = [] }
  end

  def on(event, &block)
    @listeners[event] << block
    self
  end

  def off(event)
    @listeners.delete(event)
    self
  end

  def emit(event, *args)
    @listeners[event].each { |cb| cb.call(*args) }
    self
  end

  def once(event, &block)
    wrapper = nil
    wrapper = lambda do |*args|
      block.call(*args)
      off_once(event, wrapper)
    end
    @listeners[event] << wrapper
    self
  end

  private

  def off_once(event, wrapper)
    @listeners[event].delete(wrapper)
  end
end

module MathUtils
  def self.clamp(value, min, max)
    [[value, min].max, max].min
  end

  def self.lerp(a, b, t)
    a + (b - a) * t
  end

  def self.average(arr)
    return 0.0 if arr.empty?
    arr.sum.to_f / arr.size
  end

  def self.median(arr)
    return nil if arr.empty?
    sorted = arr.sort
    n = sorted.size
    n.odd? ? sorted[n / 2] : (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0
  end

  def self.standard_deviation(arr)
    return 0.0 if arr.size < 2
    avg = average(arr)
    variance = arr.sum { |x| (x - avg)**2 } / (arr.size - 1).to_f
    Math.sqrt(variance)
  end

  def self.percentile(arr, p)
    sorted = arr.sort
    rank = p / 100.0 * (sorted.size - 1)
    lower = sorted[rank.floor]
    upper = sorted[rank.ceil]
    lower + (upper - lower) * (rank - rank.floor)
  end
end

class TokenBucket
  def initialize(capacity:, refill_rate:)
    @capacity = capacity
    @tokens = capacity
    @refill_rate = refill_rate
    @last_refill = Time.now
  end

  def consume(tokens = 1)
    refill
    return false if @tokens < tokens
    @tokens -= tokens
    true
  end

  def available
    refill
    @tokens
  end

  private

  def refill
    now = Time.now
    elapsed = now - @last_refill
    @tokens = [@tokens + elapsed * @refill_rate, @capacity].min
    @last_refill = now
  end
end

class BloomFilter
  def initialize(size: 1000, hash_count: 3)
    @size = size
    @hash_count = hash_count
    @bits = Array.new(size, false)
  end

  def add(item)
    positions(item).each { |pos| @bits[pos] = true }
    self
  end

  def include?(item)
    positions(item).all? { |pos| @bits[pos] }
  end

  private

  def positions(item)
    @hash_count.times.map do |i|
      Digest::MD5.hexdigest("#{i}:#{item}").to_i(16) % @size
    end
  end
end

module Validators
  EMAIL_REGEX = /\A[\w+\-.]+@[a-z\d\-.]+\.[a-z]+\z/i
  URL_REGEX = /\Ahttps?:\/\/[\S]+\z/i
  PHONE_REGEX = /\A[\+]?[(]?[0-9]{3}[)]?[-\s\.]?[0-9]{3}[-\s\.]?[0-9]{4,6}\z/

  def self.valid_email?(email)
    email.match?(EMAIL_REGEX)
  end

  def self.valid_url?(url)
    url.match?(URL_REGEX)
  end

  def self.valid_phone?(phone)
    phone.match?(PHONE_REGEX)
  end

  def self.valid_date?(str, format: '%Y-%m-%d')
    Date.strptime(str, format)
    true
  rescue ArgumentError, TypeError
    false
  end

  def self.strong_password?(password)
    password.length >= 8 &&
      password.match?(/[A-Z]/) &&
      password.match?(/[a-z]/) &&
      password.match?(/[0-9]/) &&
      password.match?(/[^A-Za-z0-9]/)
  end
end

class Retry
  DEFAULT_DELAYS = [1, 2, 4, 8, 16].freeze

  def initialize(max_attempts: 3, delays: DEFAULT_DELAYS, exceptions: [StandardError])
    @max_attempts = max_attempts
    @delays = delays
    @exceptions = exceptions
  end

  def run
    attempts = 0
    begin
      attempts += 1
      yield attempts
    rescue *@exceptions => e
      if attempts < @max_attempts
        sleep(@delays[[attempts - 1, @delays.size - 1].min])
        retry
      else
        raise e
      end
    end
  end
end

class Observable
  def initialize(value)
    @value = value
    @watchers = []
  end

  def value
    @value
  end

  def value=(new_val)
    old_val = @value
    @value = new_val
    @watchers.each { |w| w.call(new_val, old_val) } if new_val != old_val
  end

  def watch(&block)
    @watchers << block
    self
  end

  def unwatch_all
    @watchers.clear
    self
  end
end

class Pipeline
  def initialize
    @steps = []
  end

  def pipe(&block)
    @steps << block
    self
  end

  def run(input)
    @steps.reduce(input) { |acc, step| step.call(acc) }
  end

  def run_async(input)
    Thread.new { run(input) }
  end
end

module DateUtils
  def self.business_days_between(start_date, end_date)
    count = 0
    current = start_date
    while current <= end_date
      count += 1 unless current.saturday? || current.sunday?
      current += 1
    end
    count
  end

  def self.next_weekday(date)
    d = date + 1
    d += 1 while d.saturday? || d.sunday?
    d
  end

  def self.start_of_week(date)
    date - date.wday
  end

  def self.end_of_month(date)
    Date.new(date.year, date.month, -1)
  end

  def self.quarter(date)
    ((date.month - 1) / 3) + 1
  end
end

class Config
  def initialize(defaults = {})
    @data = defaults.dup
  end

  def set(key, value)
    @data[key.to_sym] = value
    self
  end

  def get(key, default = nil)
    @data.fetch(key.to_sym, default)
  end

  def merge!(other)
    @data.merge!(other.to_h)
    self
  end

  def to_h
    @data.dup
  end

  def to_json
    JSON.generate(@data)
  end

  def [](key)
    get(key)
  end

  def []=(key, value)
    set(key, value)
  end
end

module CollectionUtils
  def self.flatten_keys(hash, prefix: '', sep: '.')
    hash.each_with_object({}) do |(k, v), result|
      full_key = prefix.empty? ? k.to_s : "#{prefix}#{sep}#{k}"
      if v.is_a?(Hash)
        result.merge!(flatten_keys(v, prefix: full_key, sep: sep))
      else
        result[full_key] = v
      end
    end
  end

  def self.deep_merge(base, override)
    base.merge(override) do |_key, old_val, new_val|
      old_val.is_a?(Hash) && new_val.is_a?(Hash) ? deep_merge(old_val, new_val) : new_val
    end
  end

  def self.group_consecutive(arr)
    arr.chunk_while { |a, b| b - a == 1 }.to_a
  end

  def self.rotate_matrix(matrix)
    matrix.reverse.transpose
  end

  def self.zip_with(*arrays, &block)
    arrays[0].zip(*arrays[1..]).map { |group| block.call(*group) }
  end
end

class RateLimiter
  def initialize(limit:, window:)
    @limit = limit
    @window = window
    @requests = Hash.new { |h, k| h[k] = [] }
  end

  def allow?(key)
    now = Time.now.to_f
    @requests[key].reject! { |t| now - t > @window }
    return false if @requests[key].size >= @limit
    @requests[key] << now
    true
  end

  def remaining(key)
    now = Time.now.to_f
    @requests[key].reject! { |t| now - t > @window }
    @limit - @requests[key].size
  end
end

class Trie
  Node = Struct.new(:children, :terminal) do
    def initialize
      super(Hash.new, false)
    end
  end

  def initialize
    @root = Node.new
  end

  def insert(word)
    node = @root
    word.each_char do |c|
      node.children[c] ||= Node.new
      node = node.children[c]
    end
    node.terminal = true
  end

  def search(word)
    node = find_node(word)
    node&.terminal == true
  end

  def starts_with?(prefix)
    !find_node(prefix).nil?
  end

  def autocomplete(prefix)
    node = find_node(prefix)
    return [] unless node
    results = []
    collect_words(node, prefix, results)
    results
  end

  private

  def find_node(str)
    node = @root
    str.each_char do |c|
      return nil unless node.children.key?(c)
      node = node.children[c]
    end
    node
  end

  def collect_words(node, current, results)
    results << current if node.terminal
    node.children.each do |char, child|
      collect_words(child, current + char, results)
    end
  end
end

class HexEncoder
  def self.encode(str)
    str.unpack1('H*')
  end

  def self.decode(hex)
    [hex].pack('H*')
  end

  def self.to_base64(str)
    Base64.strict_encode64(str)
  end

  def self.from_base64(str)
    Base64.strict_decode64(str)
  end

  def self.sha256(str)
    Digest::SHA256.hexdigest(str)
  end

  def self.md5(str)
    Digest::MD5.hexdigest(str)
  end
end

class Scheduler
  Job = Struct.new(:id, :interval, :last_run, :callback)

  def initialize
    @jobs = {}
    @running = false
  end

  def schedule(id, interval:, &block)
    @jobs[id] = Job.new(id, interval, nil, block)
    self
  end

  def cancel(id)
    @jobs.delete(id)
    self
  end

  def tick
    now = Time.now
    @jobs.each_value do |job|
      next if job.last_run && now - job.last_run < job.interval
      job.callback.call
      job.last_run = now
    end
  end

  def pending_count
    @jobs.size
  end
end

puts "Loaded #{ObjectSpace.each_object(Module).count { |m| m.name&.start_with?('') }} modules."
puts SecureRandom.uuid