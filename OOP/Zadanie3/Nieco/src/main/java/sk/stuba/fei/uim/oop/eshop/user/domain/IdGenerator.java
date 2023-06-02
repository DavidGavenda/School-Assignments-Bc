package sk.stuba.fei.uim.oop.eshop.user.domain;

import java.util.concurrent.atomic.AtomicLong;

public class IdGenerator {

    private static final AtomicLong generator = new AtomicLong(0);

    public static long newId() {
        return generator.getAndIncrement();
    }
}
