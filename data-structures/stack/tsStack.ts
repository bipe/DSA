type Node<T> = {
    value: T,
    prev?: Node<T> // Depends on how you want to look at the problem
}

export default class Stack<T> {
    public length: number;
    private head?: Node<T>;

    constructor() {
        this.head = undefined;
        this.length = 0;
    }

    push(item: T): void {
        const newNode: Node<T> = { value: item };

        this.length++;

        if (!this.head) {
            this.head = newNode;
            return;
        }

        newNode.prev = this.head;
        this.head = newNode;
    }

    pop(): T | undefined {
        if (!this.head) {
            return undefined;
        }

        this.length--;

        const aux = this.head;
        this.head = this.head.prev;
        
        // aux and its prev pointer will be deleted by JS GC so no need to free
        return aux.value;
    }

    peek(): T | undefined {
        return this.head?.value;
    }
}