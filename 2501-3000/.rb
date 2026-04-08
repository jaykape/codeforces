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

