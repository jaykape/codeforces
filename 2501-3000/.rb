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

