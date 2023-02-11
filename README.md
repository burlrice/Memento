
# Memento

A mechanism to restore the original state of an object.

    int value = 0;
    
    using var memento = new Memento<int>(ref value);
    
    memento.Set(1); // 'value' will now be 1
    // when 'memento' goes out of scope, 'value' will be set back to 0
