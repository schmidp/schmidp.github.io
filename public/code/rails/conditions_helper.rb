module ConditionsHelper
  def self.included(base)
    base.extend ClassMethods
  end
  
  def create_conditions
    c = Conditions.new
    yield c
    c.to_conditions
  end

  module ClassMethods
    def create_conditions
      c = Conditions.new
      yield c
      c.to_conditions
    end
  end

  class Conditions
    def initialize
      @conditions = ""
      @values = []
    end
    
    def and(condition)
      add(condition, :and)
    end
    
    def or(condition)
      add(condition, :or)
    end
    
    def to_conditions
      if @conditions.blank?
        return nil
      else
        [@conditions] + @values
      end
    end
    
    private
    def add(condition, join = :and)
      join = if join == :or
        " OR " 
      else
        " AND "
      end
      
      if condition.is_a?(Array):
        @conditions.blank? ? @conditions << condition.shift : @conditions << join << condition.shift
        @values += condition
      else
        @conditions.blank? ? @conditions << condition : @conditions << join << condition
      end
      
      return
    end
  end
end